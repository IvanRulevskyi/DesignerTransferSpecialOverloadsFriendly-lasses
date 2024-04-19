#include "Function.hpp"
//Розробіть клас для динамічного масиву ( або вектору, якщо вмієте ним користуватися), який містить масив елементів. Перевантажте оператор [], щоб можна було звертатися до елементів вектора за індексом як для виводу, так і для зміни елементів (всього 2 перевантаження).
//Перевантажте оператор присвоювання =, щоб він правильно копіював дані з одного

//Class Element
Element::Element(string element1, string text1, string text2):
element1(element1),
text1(text1),
text2(text2){}

ostream& operator << (ostream& os, const Element& text)
{
    os << text.element1<<endl;
    os << text.text1<<endl;
    os << text.text2<<endl;
    return os;
}

//Class Conteiner
void Conteiner::addElement(const Element& text)
{
    el.emplace_back(text);
}

Element Conteiner::operator[] (int index) const
{
    if (index < 0 || index > el.size())
    {
        cout<<"error size";
    }
    return el[index];
}

Element& Conteiner::operator[] (int index)
{
    if (index < 0 || index > el.size())
    {
        cout<<"error size";
    }
    return el[index];
}


//Завдання 2 (Словник)
//Словник: Реалізуйте клас словника, який зберігає слова та їх відповідні значення.
//Перегрузіть оператор [], щоб можна було отримувати значення, шукаючи слово за його ключем, наприклад, dictionary["word"]
    
// Class Item

Item::Item(string key, string word):
word {word},
key {key}{}

string Item::getWord() const
{
    return word;
}

string Item::getKey() const
{
    return key;
}

ostream& operator<<(ostream& os, const Item& text)
{
    os << text.word << endl;
    return os;
}

// Class Dictionary

void Dictionary::addWord(const Item& text)
{
    items.emplace_back(text);
}

Item Dictionary::operator [] (string index) const
{
    for (size_t i = 0; i < items.size(); i++)
    {
        if (items[i].getKey() == index)
        {
            return items[i];
        }
    }
    throw out_of_range("Key not found");
}
