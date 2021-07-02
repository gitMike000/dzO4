#include <iostream>
#include <string>
#include "ArrayInt.h"
#include <set>
#include <vector>

using namespace std;

// ---- Task 3

class Card {
public:
  enum znashen {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
           JACK, QUEEN, KING};
  enum mast {CLUBS, DIAMONDS, HEARTS, SPADES};

  Card(znashen r, mast s, bool ifUp): m_Znashen(r), m_Mast(s), m_IsFaceUp(ifUp)
  {}

  // возвращает значение карты, пока можно считать, что туз = 1
  int GetValue() const
  {
   int value = 0;
   if (m_IsFaceUp)
    {
      value = m_Znashen;
      if (value > 10) value = 10;
    }
   return value;
  };

  // переворачивает карту
  void Flip()
  {
     m_IsFaceUp = !(m_IsFaceUp);
  };

private:
  znashen m_Znashen;
  mast m_Mast;
  bool m_IsFaceUp;
};

class Hand
{

protected:
  vector <Card*> m_Cards;

public:
  Hand()
  {
   m_Cards.reserve(7);
  }
         ;

  // добавляет в коллекцию карт новую карту
  void Add(Card* pCard)
  {
    m_Cards.push_back(pCard);
  }

  // очищает руку от карт
  void Clear()
  {
    //iterate through vector, freeing all memory on the heap
    vector <Card*>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
      delete *iter;
      *iter = 0; //get rid of dangling pointer - null pointer
    }
    m_Cards.clear();
  }

  // возвращает сумму очков карт руки, туз принимает значения 1 или 11
  int GetTotal() const
{

  //если нет карт, возвращает 0
  if (m_Cards.empty()) return 0;

  // если первая карта 0, то карты закрыта, возвращает 0
  if (m_Cards[0]->GetValue() == 0) return 0;

  // сложение значения карт, относимся к каждому тузу как к 1
  int total = 0;
  vector<Card*>::const_iterator iter;
  for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
  total += (*iter)->GetValue();

  // определяем, есть ли в руке туз
  bool containsAce = false;
  for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
  if ((*iter)->GetValue() == Card::ACE)
    containsAce = true;

  // если в руке есть туз, а сумма достаточно низкая, то туз считается 11
  if (containsAce && total <= 11)
  { // добавляем только 10, так как мы уже добавили 1 для туза
   total += 10;
  }

  return total;
}

  ~Hand()
  {
    Clear();
  }
};

int main()
{
    cout << "Task 1" << endl;
//    Добавить в контейнерный класс, который был написан в этом уроке, методы:
//    - для удаления последнего элемента массива (аналог функции pop_back() в векторах)
//    - для удаления первого элемента массива (аналог pop_front() в векторах)
//    - для сортировки массива
//    - для вывода на экран элементов.
    ArrayInt d(5);
    d[0]=4;
    d[1]=5;
    d[2]=8;
    d[3]=1;
    d[4]=2;
    d.print();
    d.sort(true);
    d.print();
    d.sort(false);
    d.print();
    d.pop_back();
    d.print();
    d.pop_front();
    d.print();

    cout << endl << "Task 2" << endl;
//   Дан вектор чисел, требуется выяснить, сколько среди них различных.
//   Постараться использовать максимально быстрый алгоритм.
    set<int> N;
    vector<int> NV = {1,2,3,4,3,2,3,4,5,6,34,56,3,2,6,4,2,3,4,4};
    cout << "vector:";

    for(auto i:NV) {
      cout << i << " ";
      N.insert(i);
    }
    cout << endl << "vector size=" << NV.size() << endl;

    for(auto i : N)
     cout << i << ' ';
    cout << endl << "Число различных чисел="<< N.size() << endl;

    cout << endl << "Task 3" << endl;
//    Реализовать класс Hand, который представляет собой коллекцию карт.
//    В классе будет одно поле: вектор указателей карт (удобно использовать вектор,
//    т.к. это по сути динамический массив, а тип его элементов должен быть - указатель
//    на объекты класса Card). Также в классе Hand должно быть 3 метода:
//    - метод Add, который добавляет в коллекцию карт новую карту,
//      соответственно он принимает в качестве параметра указатель на новую карту
//    - метод Clear, который очищает руку от карт
//    - метод GetValue, который возвращает сумму очков карт руки
//      (здесь предусмотреть возможность того, что туз может быть равен 11).
    cout << "See code" << endl;

    return 0;
}
