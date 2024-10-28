#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <stdio.h>
#include <cwchar>
using namespace std;
// функция для 2В
int identify_capital(char letter) {
    string nums = "ABCDEFGHIJKLMNOPQRTSTUVWXYZ";
    short result{ 0 };
    for (int i = 0; i < nums.length(); i++) {
        if (nums[i] == letter) {
            return 1;
        }
    }
    if (result == 0) {
        return 0;
    }
}
int identify_number(char number) {
    string nums = "0123456789";
    for (int i = 0; i < 10; i++) {
        if (number == nums[i]) {
            return 1;
        }
    }
    return 0;
}
// функция для 3А
string replacement(string str) {
    for (int i = 0; i < str.length() - 3; i++) {
        if (str.substr(i, 3) == "min") {
            str[i] = 'M'; str[i + 1] = 'A'; str[i + 2] = 'X';
            i += 3;
        }
    }
    return str;
}
// функция для 3B
string ku(string str) {
    string result, app{ "ku-ku" };
    for (int i = 0; i < str.length(); i++) {
        if (i == 0 && str[5] == ' ') {
            bool key1 = true;
            for (int j = 0; j < 5; j++) {
                if (str[j] == ' ') {
                    key1 = false;
                }
            }
            if (key1 == true) {
                result += app;
                i += 4;
            }
            else {
                result += str[i];
            }
        }
        else if (str[i] == ' ' && i + 5 < str.length()) {
            if (str[i + 1] != ' ' && str[i + 2] != ' ' && str[i + 3] != ' ' && str[i + 4] != ' ' && str[i + 5] != ' ' && str[i + 6] == ' ' || str[i + 5] == str.back()) {
                result = result + ' ' + app;
                i += 5;
            }
            else {
                result += ' ';
            }
        }
        else {
            result += str[i];
        }
    }
    return result;
}
// функция для 3C
string replacementC(string str) {
    string new_str;
    bool key = true;
    for (int i = 0; i < str.length(); i++) {
        if (str.substr(i, 5) == "ku-ku") {
            new_str += "ku-ka-re-ku";
            i += 5;
            key = false;
        }
        else {
            new_str += str[i];
        }
    }
    if (key == true) {
        new_str.insert(str.length() / 2, "ku-ku ku-ku ku-ku");
        return new_str;
    }
    else {
        return new_str;
    }
}
// функция для 3D
string del_ku(string str) {
    string new_str;
    for (int i = 0; i < str.length(); i++) {
        if (str.substr(i, 5) == "ku-ku") {
            i += 4;
        }
        else {
            new_str += str[i];
        }
    }
    return new_str;
}
// функция для 3E
string del_after_ku(string str) {
    short counter;
    for (int i = 0; i < str.length(); i++) {
        if (str.substr(i, 5) == "ku-ku") {
            counter = i;
            i += 4;
        }
    }
    return str.erase(counter + 5);

}
// задание 3F
short cnt_words(string str) {
    short cnt{0};
    for (int i = 0; i < str.length(); i++) {
        switch (str[i]) {
        case ',': str.replace(i, 1, "."); break;
        case ':': str.replace(i, 1, "."); break;
        case ';': str.replace(i, 1, "."); break;
        case '!': str.replace(i, 1, "."); break;
        case '?': str.replace(i, 1, "."); break;
        case '"': str.replace(i, 1, "."); break;
        case '-': str.replace(i, 1, "."); break;
        case ' ': str.replace(i, 1, "."); break;
        }
    }
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != '.') {
            cnt++;
            while (str[i] != '.' && i < str.length()) {
                i++;
            }
        }
    }
    return cnt;
}
// задание 3G
bool check_balance(string str) {
    short in_paren{ 0 }, out_paren{ 0 };
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ')') {
            return false;
        }
        else if (str[i] == '(') {
            in_paren++;
            for (int j = i + 1; j < str.length(); j++) {
                if (str[j] == '(') {
                    in_paren++;
                }
                else if (str[j] == ')') {
                    out_paren++;
                }
            }
            i = str.length();
        }
    }
    if (in_paren == out_paren) {
        return true;
    }
    else {
        return false;
    }
}
// задание 3H
string del_paren(string str) {
    short open_index{ 0 };
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            open_index = i;
        }
        else if (str[i] == ')' && open_index != 0) {
            str.erase(open_index, i - open_index + 1);
            i = open_index - 1;
            open_index = 0;
        }
    }
    return str;
}
// задание 4
int from_roma_to_dec(string str) {
    int nums[50]{};// в свежей версии компилятора в параметре указываем str.length()
    int result{ 0 };
    for (int i = 0; i < str.length(); i++) {
        switch (str[i]) {
        case 'I': nums[i] = 1; break;
        case 'V': nums[i] = 5; break;
        case 'X': nums[i] = 10; break;
        case 'L': nums[i] = 50; break;
        case 'C': nums[i] = 100; break;
        case 'D': nums[i] = 500; break;
        case 'M': nums[i] = 1000; break;
        }
    }
    for (int i = 0; i < str.length(); i++) {
        cout << nums[i] << " ";
    }
    short prel{ 0 };
    cout << endl;
    for (int i = 0; i < str.length(); i++) {
        result += nums[i];
        if (nums[i] < nums[i + 1] && i != str.length() - 1) {
            prel += (nums[i] * 2);
        }
    }
    cout << result << "\t" << prel << endl;
    return result - prel;
}
int main() {
    setlocale(LC_ALL, "RU");
    // задание 1
    string name, sname, pat; cin >> name >> pat >> sname;
    cout << sname << " " << name << " " << pat << endl;
    cout << sname[0] << "." << name[0] << "." << pat[0] << endl;
    cout << sname << " " << (char)toupper(char(name[0])) << '.' << (char)(toupper(char(pat[0]))) << "." << endl;
    // задание 2А
    string str = "123abc-S-s-+++SSSaaaAAAssss5678";
    short cnt_S{ 0 }, cnt_s{ 0 };
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'S') {
            cnt_S++;
        }
        else if (str[i] == 's') {
            cnt_s++;
        }

    }
    short summ_s = cnt_s + cnt_S;
    // cout << "Кол-во S: " << cnt_S << endl;
    // cout << "Кол-во s: " << cnt_s << endl;
    // cout << "Кол-во S+s: " << cnt_S+cnt_s << endl;

    // задание 2Б
    string nums = "0123456789";
    short cnt_number = 0;
    for (int i = 0; i < str.length(); i++) {
        for (int j = 0; j < 10; j++) {
            if (str[i] == nums[j]) {
                cnt_number++;
            }
        }
    }
    // cout << "Кол-во цифр: "<< cnt_number << endl;

    //задание 2Б (способ 2)
    short cnt_nmb = 0;
    for (int i = 0; i < str.length(); i++) {
        for (int j = 0; j < 10; j++) {
            if (str[i] == char(j)) {
                str.replace(i, 1, "0");
            }
        }
        if (str[i] == '0') {
            cnt_nmb++;
        }
    }
    // задание 2В
    short cnt_capital{ 0 };
    for (int i = 0; i < str.length(); i++) {
        cnt_capital += identify_capital(str[i]);
    }
    // cout << "Кол-во заглавных букв: "<< cnt_capital<< endl;

    // 2Г
    string str_new = str;
    for (int i = 0; i < str.length(); i++) {
        if (identify_number(str[i]) == 1) {
            str_new[i] = '5';
        }
        else if (identify_capital(str[i]) == 0) {
            str_new[i] = (char)toupper(str[i]);
        }
        else if (identify_capital(str[i]) == 1) {
            str_new[i] = str[i];
        }
        else {
            str_new[i] = str[i];
        }
    }
    // cout << "Новая строка: "<<str_new << endl;
    printf("Исходная строка: %s \n Кол-во S: %d \n Кол-во s: %d \n Кол-во s и S: %d \n Кол-во цифр: %d \n Кол-во заглавных букв: %d \n Новая строка: %s", str.c_str(), cnt_S, cnt_s, summ_s, cnt_number, cnt_capital, str_new.c_str());

    // задание 3А
    string testA = "tminfiudfmihvfreminfwbhin";
    cout << endl << replacement(testA) << endl;

    // задание 3B
    string testB = "Letss try to check how working this program birds";
    cout << ku(testB) << endl;

    // задание 3C
    string testC = "abcku-kuasvbdku-kunjsku-ku";
    string test2C = "yfghtbcygfc";
    cout << replacementC(test2C) << endl;

    // задание 3D
    string test3D = "ku-kuabcdku-kujfku";
    cout << del_ku(test3D) << endl;

    // задание 3E
    string test3E = "zxcvku-kuytreku-kuqwet";
    cout << del_after_ku(test3E) << endl;

    // задание 3F
    string test3F = "test.,   feu  ,.:;tr    a,,,,,po:::";
    cout << "Кол-во слов: " << cnt_words(test3F) << endl;;

    // задание 3G
    string tets3G = "((a+b)+c)*5/2)";
    cout << check_balance(tets3G) << endl;

    // задание 3H
    string test3H = "abc(ascasc)ijw(acnj)(";
    cout << del_paren(test3H) << endl;

    // задание 4
    string test4 = "MCMLXXIV";
    cout << from_roma_to_dec(test4) << endl;

    return 0;
}
