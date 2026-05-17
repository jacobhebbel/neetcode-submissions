class Solution {
public:

    string padChar(char c) {
        string newC = to_string(int(c));
        while (newC.size() < 3)
            newC = "0" + newC;
        cout << "new char: " << newC << endl;
        return newC;
    }

    string encode(vector<string>& strs) {
        string encoding = "";

        for (string word : strs) {
            for (char c : word)
                encoding += padChar(c);
            encoding += "-";
        }

        cout << "finished encoding: " << encoding << endl;
        return encoding;
    }

    string parseStr(string s) {
        string sol = "";
        for (int i = 0; i < s.size(); i += 3) {
            int asciiNum = stoi(s.substr(i, 3));
            cout << "parsed num " << asciiNum << " as " << char(asciiNum) << endl;
            sol += char(asciiNum);
        }

        cout << "parsed str " << sol << endl;
        return sol;
    }

    vector<string> decode(string s) {
        
        vector<string> solution;
        
        while (s.find("-") != string::npos) {
            int breakIndex = s.find("-");
            string parsedString = parseStr(s.substr(0, breakIndex));
            solution.push_back(parsedString);
            s = s.substr(breakIndex + 1);
        }
        
        return solution;    
    }
};
