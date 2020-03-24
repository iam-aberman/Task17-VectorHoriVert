# Task17-VectorHoriVert
Задача по программированию на наследование и виртуальные методы ММ МГУ 2020

МехМат МГУ;
Весенний семестр 2020;
2 курс, 3 поток;
Чин-Го-Пин Осип

http://lectures.stargeo.ru/tasks-2019/kr1-2.pdf

-----------------------------------------------------------------------------------------

Общие условия всех задач из данного цикла : 

В каждой задаче должен быть сделан базовый класс, решающий задачу. Пусть он называется CData.

В каждом классе должна быть создана [чисто] виртуальная функция вывода данных класса в файл вида
virtual int output(const char *FileName=NULL)=0;

От данного класса CData надо породить два класса CData0 и CData1, в первом из которых переопределена функция
int output(const char *FileName);
как функция вывода данных класса в файл в одну строку, а во втором данная функция определена как функция вывода 
данных класса в столбец (т.е. по одному элементу данных в одну строку).

В файле с исходными данными в каждой строке задаются данные для одного экземпляра класса, порожденного от CData. 
Данные задачи задаются в каждой строке в виде:
I FileName Data
где I = 0 или = 1, FileName — имя выходного файла, Data — все данные одного объекта, разделенные пробелами.
Для каждой строки исходного файла надо создать класс CData0, если I == 0, либо надо создать класс CData1, 
если I == 1. Созданный класс надо заполнить данными из введенной строки. Имя выходного файла следует 
занести в соответствующее поле созданного класса.

Все созданные классы надо поместить в массив указателей на базовый класс CData **arr;.
Каждый новый объект должен создаваться функцией вида CData *CreateData(const char *str, CFabricData **f);.
где f — массив фабрик для создания I-го дочернего класса от CData.
Далее надо в цикле для каждого объекта из массива arr вызвать функцию output().

-----------------------------------------------------------------------------------------

Задача 17 :

17. Определить класс CRat для работы с вектором дробей вида pi/qi, где pi — целое, qi — натуральное. Длина вектора задается в конструкторе класса. В классе должны быть определены необходимые конструкторы, деструктор, операторы присваивания, сложения, вычитания, скалярного умножения.

-----------------------------------------------------------------------------------------

Задача делится на три пункта: 

1) Реализовать условие.
2) Переделать задачу с активным использованием STL.
3) Добавить многопоточность в арифметические операторы, используя OpenMP.

В данном репозитории приведено решение второго пункта задачи.

-----------------------------------------------------------------------------------------

Решение задачи :

-> В качестве решения в рамках отдельного пространства имен был создан шаблонный класс «Vector», от которого были порождены два класса-наследника с необходимыми функциями вывода : «VectorHori», «VectorVert».

-> Внутри данного пространства имен также реализован фабричный метод создания объектов класса. 

-> В конкретной задаче в качестве элементов вектора используется класс рациональных дробей Rational.  Данный класс конструирует рациональную дробь, автоматически сокращая числитель и знаменатель. 
Данный класс был реализован в процессе прохождения курса «Основы разработки на C++ - Белый пояс» (coursera.org).

-> В решении задачи применяется STL. Вместо *char - std::string, *elementsType - std::vector<elementsType>.

-> Для хранения указателей на объекты классов-наследников используется std::shared_ptr вместо обычного указателя; таким образом необходимость вручную чистить память отпадает.

-> В качестве дополнительного требования преподавателя изменен формат строки исходного файла. Вместо числа 0/1, обозначающего тип класса-наследника, используется прямое обозначение: Hori/Vert.

-> Название файла вывода для каждого вектора не вносится внутрь полей класса.

-----------------------------------------------------------------------------------------

