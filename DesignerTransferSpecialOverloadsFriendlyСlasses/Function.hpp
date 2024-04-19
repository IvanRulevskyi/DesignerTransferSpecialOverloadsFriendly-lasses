#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//Розробіть клас для динамічного масиву ( або вектору, якщо вмієте ним користуватися), який містить масив елементів. Перевантажте оператор [], щоб можна було звертатися до елементів вектора за індексом як для виводу, так і для зміни елементів (всього 2 перевантаження).
//Перевантажте оператор присвоювання =, щоб він правильно копіював дані з одного
class Element
{
    string element1;
    string text1;
    string text2;
public:
    Element()= default;
    Element(string element1, string text1, string text2);
    friend ostream& operator << (ostream& os, const Element& text);
};

class Conteiner
{
    vector<Element> el;
public:
    void addElement(const Element& text);
    Element operator[] (int index) const;
    Element& operator[] (int index);
};
//Завдання 2 (Словник)
//Словник: Реалізуйте клас словника, який зберігає слова та їх відповідні значення.
//Перегрузіть оператор [], щоб можна було отримувати значення, шукаючи слово за його ключем, наприклад, dictionary["word"]

class Item
{
private:
    string key;
    string word;
    
public:
    Item(string key, string word);
    
    string getWord() const;
    string getKey() const;
    friend ostream& operator<<(ostream& os, const Item& text);
};

class Dictionary
{
    vector<Item> items;
    
public:
    void addWord(const Item& text);
    Item operator [] (string index) const;
};

