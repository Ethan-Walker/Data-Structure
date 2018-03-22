#include <iostream>

using namespace std;

class Person
{
  public:
    Person();
    Person(string name);
    Person(int age);
    Person(string name, int age);
    virtual void Introduce()
    {
        cout << "姓名: " << name << " ,年龄: " << age << endl;
    }
    void setName(string n)
    {
        name = n;
    }
    void setAge(int a)
    {
        age = a;
    }

  protected:
    string name;
    int age;
}

class Star : public Person
{
  public:
    void setWorkarea(string area)
    {
        workarea = area;
    }
    void setTime(string t)
    {
        startTime = t;
    }

  protected:
    string workarea;  // 工作领域
    string startTime; //出道时间

}

class SingerStar : public Star
{
  public:
    void setWorks(string works)
    {
        representativeWorks = works;
    }

  protected:
    string representativeWorks; // 代表作品
}

class MovieStar : public Star
{
    void setWorks(string works)
    {
        representativeWorks = works;
    }

  protected:
    string representativeWorks;
}

int main()
{
    Person person= new Person("张三",32);
    person.Introduce();
    return 0;
}
