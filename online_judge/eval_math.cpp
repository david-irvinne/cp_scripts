#include <bits/stdc++.h>
using namespace std;

string hexify(const string &s) {
    ostringstream oss;
    for (unsigned char c : s) {
        oss << std::hex << std::uppercase << setw(2) << setfill('0') << (int)c << " ";
    }
    return oss.str();
}

string replaceAll(string s, const string &from, const string &to) {
    size_t pos = 0;
    while ((pos = s.find(from, pos)) != string::npos) {
        s.replace(pos, from.size(), to);
        pos += to.size();
    }
    return s;
}

// Normalize common problematic unicode sequences to ASCII equivalents.
string normalize_input(string s) {
    // NBSP -> space
    s = replaceAll(s, "\xC2\xA0", " ");
    // Unicode "asterisk operator" U+2217 (UTF-8: E2 88 97) -> '*'
    s = replaceAll(s, "\xE2\x88\x97", "*");
    // optionally accept caret ^ as power
    // remove carriage returns
    s = replaceAll(s, "\r", "");
    // remove zero-width space (U+200B) if present (utf8: E2 80 8B)
    s = replaceAll(s, "\xE2\x80\x8B", "");
    return s;
}

long long ipow(long long base, long long exp) {
    if (exp < 0) throw runtime_error("negative exponent not supported");
    long long res = 1;
    long long b = base;
    while (exp) {
        if (exp & 1) res = res * b;
        b = b * b;
        exp >>= 1;
    }
    return res;
}

bool isOperator(const string &t) {
    return t == "+" || t == "-" || t == "" || t == "/" || t == "*";
}

int prec(const string &op) {
    if (op == "**") return 4;
    if (op == "*" || op == "/") return 3;
    if (op == "+" || op == "-") return 2;
    return 0;
}

bool isRightAssoc(const string &op) { return op == "**"; }

vector<string> tokenize(const string &s) {
    vector<string> tokens;
    int n = (int)s.size();
    int i = 0;
    bool prevIsOp = true;
    while (i < n) {
        unsigned char ch = s[i];
        if (isspace(ch)) { i++; continue; }
        if (isdigit(ch)) {
            int j = i;
            while (j < n && isdigit((unsigned char)s[j])) j++;
            tokens.push_back(s.substr(i, j - i));
            i = j;
            prevIsOp = false;
        } else if (s[i] == '(') {
            tokens.push_back("("); i++; prevIsOp = true;
        } else if (s[i] == ')') {
            tokens.push_back(")"); i++; prevIsOp = false;
        } else if (s[i] == '+' || s[i] == '-') {
            if (prevIsOp || tokens.empty() || tokens.back() == "(") {
                if (s[i] == '+') { i++; continue; }
                else { tokens.push_back("0"); tokens.push_back("-"); i++; prevIsOp = true; }
            } else { tokens.push_back(string(1, s[i])); i++; prevIsOp = true; }
        } else if (s[i] == '*') {
            if (i + 1 < n && s[i+1] == '*') {
                tokens.push_back("**"); i += 2; prevIsOp = true;
            } else {
                tokens.push_back("*"); i++; prevIsOp = true;
            }
        } else if (s[i] == '/') {
            tokens.push_back("/"); i++; prevIsOp = true;
        } else if (s[i] == '^') { // accept caret as power
            tokens.push_back("**"); i++; prevIsOp = true;
        } else {
            // show hex so user can inspect non-ascii bytes
            string byte(1, s[i]);
            throw runtime_error("unexpected character in input: '" + byte + "' hex: " + hexify(byte));
        }
    }
    return tokens;
}

vector<string> toRPN(const vector<string> &tokens) {
    vector<string> output;
    vector<string> ops;
    for (const string &t : tokens) {
        if (!t.empty() && (isdigit((unsigned char)t[0]) || (t.size() > 1 && t[0] == '-' && isdigit((unsigned char)t[1])))) {
            output.push_back(t);
        } else if (isOperator(t)) {
            while (!ops.empty() && isOperator(ops.back())) {
                string top = ops.back();
                if ((!isRightAssoc(t) && prec(t) <= prec(top)) ||
                    (isRightAssoc(t) && prec(t) < prec(top))) {
                    output.push_back(top);
                    ops.pop_back();
                } else break;
            }
            ops.push_back(t);
        } else if (t == "(") {
            ops.push_back(t);
        } else if (t == ")") {
            while (!ops.empty() && ops.back() != "(") {
                output.push_back(ops.back()); ops.pop_back();
            }
            if (!ops.empty() && ops.back() == "(") ops.pop_back();
            else throw runtime_error("mismatched parentheses");
        } else {
            throw runtime_error("unknown token during RPN conversion: '" + t + "' hex: " + hexify(t));
        }
    }
    while (!ops.empty()) {
        if (ops.back() == "(" || ops.back() == ")") throw runtime_error("mismatched parentheses");
        output.push_back(ops.back()); ops.pop_back();
    }
    return output;
}

long long evalRPN(const vector<string> &rpn) {
    vector<long long> st;
    for (const string &t : rpn) {
        if (!t.empty() && (isdigit((unsigned char)t[0]) || (t.size() > 1 && t[0] == '-' && isdigit((unsigned char)t[1])))) {
            st.push_back(stoll(t));
        } else if (isOperator(t)) {
            if (st.size() < 2) throw runtime_error("invalid expression: insufficient operands");
            long long b = st.back(); st.pop_back();
            long long a = st.back(); st.pop_back();
            long long res = 0;
            if (t == "+") res = a + b;
            else if (t == "-") res = a - b;
            else if (t == "*") res = a * b;
            else if (t == "/") {
                if (b == 0) throw runtime_error("division by zero");
                res = a / b;
            } else if (t == "**") res = ipow(a, b);
            else throw runtime_error("unsupported operator " + t);
            st.push_back(res);
        } else {
            throw runtime_error("invalid token in RPN evaluation: '" + t + "' hex: " + hexify(t));
        }
    }
    if (st.size() != 1) throw runtime_error("invalid final stack size");
    return st.back();
}

string StringCalculate(string raw) {
    try {
        string s = normalize_input(raw);
        auto tokens = tokenize(s);
        // debug: print tokens (comment out in final)
        // for (auto &tk : tokens) cerr << "TK: '" << tk << "' hex: " << hexify(tk) << "\n";
        auto rpn = toRPN(tokens);
        long long res = evalRPN(rpn);
        return to_string(res);
    } catch (const exception &e) {
        return string("ERROR: ") + e.what();
    }
}

int main() {
    cout << StringCalculate("100*2**4") << "\n"; // expect 1600
    cout << StringCalculate("2*3*2") << "\n";  // expect 512
    // If you still get ERROR with unknown token, copy the ERROR text (hex) and kirim ke saya.
    return 0;
}
