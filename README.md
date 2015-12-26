﻿#Перевод арифметического выражения в постфиксную форму [![Build Status](https://travis-ci.org/Alexander-Khlybov/mp2-lab3-postfix.svg)](https://travis-ci.org/Alexander-Khlybov/mp2-lab3-postfix)
###(реализация на основе стеков на линейных односвязных списках)


## Содержание

* [Постановка задачи](#Постановка-задачи)
* [Руководство пользователя](#Руководство-пользователя)
* [Руководство программиста](#Руководство-программиста)
	* [Используемые инструменты](#Используемые-инструменты)
	* [Общая структура проета](#Общая-структура-проекта)
	* [Описание структуры программы](#Описание-структуры-программы)
	* [Схема наследования классов](#Схема-наследования-классов)
	* [Описание структур данных](#Описание-структур-данных)
		* [Список](#Список)
		* [Стек](#Стек)
	* [Описание алгоритмов](#Описание-алгоритмов)
		* [Перевод выражения в постфиксную форму](#Перевод-выражения-в-постфиксную-форму)
		* [Подсчет выражения в постфиксной форме](#Подсчет-выражения-в-постфиксной-форме)
* [Заключение](#Заключение)
* [Приложения](#Литература)

##Постановка задачи

**Цель работы** - разработать статическую библиотеку, реализующую динамические структуры данных:

	* Линейный односвязный список
	* Стек, основынный на линейном односвязном списке

Написать тестирующую программу для каждой структуры данных с помощью Google C++ Testing Framework.

Написать приложения для демонстрации работы всех методов стека и списка.

Разработать алгоритм перевода арифметического выражения из инфиксной формы в постфиксную, также реализовать алгоритм вычисления значения выражения, записанного в постфиксной форме. Создать консольное приложение для демонстрации работы алгоритмов, где:
	- Входные данные - арифметическое выражение в инфиксной форме, значения переменных
	- Результат - арифметическое выражение в постфиксной форме, численный результат

##Руководство пользователя
###*Запуск приложения и ввод данных*

Программа предназначена для перевода арифметического выражения, записанного в инфиксной форме, в обратную польскую запись, а также вычисление значения выражения, уже переведенного в постфиксную форму, на основе значений переменных, вводимых пользователем.

Чтобы запустить программу необходимо открыть исполняемый файл **sample_postfix.exe** и следовать инструкциям программы.

**Пример:**

1) Введите арифметическое выражение и нажмите "Enter"

![step1](/Rept/step1.png)

2) Программа выдаст выражение, записанное в постфиксном виде

![step2](/Rept/step2.png)

3) Введите численные значения переменных

![step3](/Rept/step3.png)

4) Программа выдаст результат вычисленного выражения

![step4](/Rept/step4.png)

**Внимание!**
Если было введено некорректное выражение, на втором шаге программа выдаст соответствующее сообщение об ошибке. Выполнение дальнейших этапов программы, соответственно, отменяется.

![step2error](/Rept/step2error.png)

##Руководство программиста

###Используемые инструменты

	- Среда разработки Microsoft Visual Studio Community (2015);
	- Фреймворк для написания автоматических тестов Google Test;
	- Система контроля ферсий Git;
	- Система автоматического тестирования Travis-CI.

###Общая структура проекта

* [`gtest`](https://github.com/Alexander-Khlybov/mp2-lab3-postfix/tree/master/gtest) - библиотека GoogleTest;
* [`src`](https://github.com/Alexander-Khlybov/mp2-lab3-postfix/tree/master/src) - директория для размещения файлов исходноо кода;
* [`include`](https://github.com/Alexander-Khlybov/mp2-lab3-postfix/tree/master/include) - директория для размещения заголовочных файлов;
* [`samples`](https://github.com/Alexander-Khlybov/mp2-lab3-postfix/tree/master/samples) - директория для размещения исходных кодов приложений;
* [`test`](https://github.com/Alexander-Khlybov/mp2-lab3-postfix/tree/master/test) - директория для размещения тестов;
* [`sln`](https://github.com/Alexander-Khlybov/mp2-lab3-postfix/tree/master/sln/) - директория с файлими решений (на данный момент Visual Studio 2015);
* [`Rept`](https://github.com/Alexander-Khlybov/mp2-lab3-postfix/tree/master/Rept) - директория с материалами для отчета;
* Служебные файлы:
  * `.gitignore` - перечень расширений файлов, игнорируемых Git при добавлении файлов в репозиторий;
  * `CMakeLists.txt` - корневой файл для сборки проекта с помощью CMake;
  * `.travis.yml` - конфигурационный файл для системы автоматического тестирования Travis-CI.


###Описание структуры программы

Программа состоит из 6 проектов:

* `gtest` - фреймворк Google Test;
* `postfix` - статическая библиотека, содержащая объявление и реализацию шаблонных классов *Node*, *List*, *Stack*, а также класса *Postfix*:
	* *Node* - описывает узел списка. Хранит значение ключа и указатель на следующий узел (Node<KeyType>* );
	* *List* - класс "список". Агрегирует в себе класс *Node*;
	* *Stack* - класс "стек". Агрегирует в себе класс *List*;
	* *Postfix* - класс для перевода арифметического выражения в постфиксную форму и вычисления значения выражения. Подробнее в разделе [*Описание алгоритмов*](#Описание-алгоритмов);
* `sample_list` - консольное приложение для демонстрации работы методов класса *List*;
* `sample_stack` - консольное приложение для демонстрации работы методов класса *Stack*;
* `sample_postfix` - консольное приложение, рассмотренное в [*Руководстве программиста*](#Руководство-программиста);
* `test` - консольное приложение для проверки правильности реализации классов *List* и *Stack*.

###Схема наследования классов

![diagramOfClassInheritance](/Rept/diagramOfClassInheritance.png)

###Описание структур данных

####Список

**Линейный односвязный список** - динамическая структура данных, состоящая из однотипных элементов, которые связаны между собой посредством указателей. Звено списка содержит два поля (или больше): ключ и указатель на следующее звено. Последний элемент списка хранит указатель в NULL - признак конца. Указатель на первый элемент списка есть указатель на сам список.

![list](/Rept/list.png)

В лабораторной работе реализован класс *List*, содержащий в себе нижеизложенные методы:

* `List (void)` - сонструктор по умолчанию
* `List (const List<KeyType>&)` - конструктор копирования
* `~List (void)` - деструктор
* `int operator== (const List<KeyType>&)const` - сравнение списков на равенство
* `int operator!= (const List<KeyType>&)const` - сравнение списков на неравенство
* `Node<KeyType>* find (const KeyType&)const` - поиск узла с заданным ключом
* `void push (const KeyType&)` - добавление элемента к началу списка
* `void pushBefore (const KeyType&, const KeyType&)` - вставка элемента, переданного вторым патаметром, до элемента, переданного первым параметром
* `void pushAfter (const KeyType&, const KeyType&)` - вставка элемента, переданного вторым патаметром, после элемента, переданного первым параметром
* `void pushEnd (const KeyType&)` - вставка элемента в конец
* `void remove (const KeyType&)` - удаление узла с заданным ключом
* `Node<KeyType>* getFirst (void)const` - получить указатель на первый элемент списка
* `void print (void)const` - печать списка

Как видно из написанного выше, данный класс реализован как шаблонный. Это позволяет создавать списки различных типов данных.

 Представленный набор методов достаточен для реализации иных структур данных, в частности, стека. Пример использования списка находится в приложении **sample_list.exe**.


####Стек

**Стек** - абстрактный тип данных, представляющий собой набор однотипных элементов, организованных по принципу LIFO (last in - first out). Понятие стека было введено Аланом Тьюрингом в 1946 году.

В данной лабораторной работе стек основан на основе линейного односвязного списка.

![stack](/Rept/stack.png)

В рабораторной работе реализован класс Stack (агрегирует в себе объект класса List), содержащий нижеизложенные методы:

* `Stack (void)` - конструктор по умолчанию (явно вызывает констлуктор списка)
* `Stack (const Stack<KeyType>&)` - конструктор копирования
* `~Stack (void)` - деструктор
* `int operator== (const Stack<KeyType>&)const` - сравнение на равенство
* `int operator!= (const Stack<KeyType>&)const` - сравнение на неравенство
* `int isEmpty (void)const` - проверка на пустоту
* `int isFull (void)const` - проверка на полноту
* `void push (const KeyType&)` - положить элемент на вершину стека
* `KeyType pop (void)` - изъять элемент с вершины стека
* `KeyType peek (void)const` - просмотр головы стека
* `void print (void)const` - печать стека

Как и класс *List*, класс *Stack* реализован шаблоным.

Пример, показывающий основные операции со стеком, находится в приложении **sample_stack.exe**.

###Описание алгоритмов
####Перевод выражения в постфиксную форму
#####Описание метода ***string rewriteLineFromInfixToPostfix(const string&)const***

0. Начальная проверка корректности введенной строки.
1. Каждой операции ставится приоритет (для установки связи между операцией и приоритетом используется ассоциативный массив **std::map<char, int>**). Значения приоритетов:

	* * -> 3
	* / -> 3
	* - -> 2
	* + -> 2
	* ( -> 1

2. Сождается два стека, которые хранят элементы символьного типа данных: **result**(хранит постфиксную форму) и **operationsStack**(хранит операции)

3. В цикле просматривается строка в инфиксной форме. При просмотре строки возможны несколько ситуаций:
	* Встретился пробел. Тогда переходим к следующей итерации
	* Встретился операнд. Добавляется в стек **result**
	* Встретилась операция, тогда она кладется в стек **operationsStack**, если:
		* приоритет текущей операции равен или выше приоритета операции, лежащей на вершине стека **operationsStack**
		* стек **operationsStack** пуст

	* Встретилась операция, но её приоритет наже приоритета операции, лежащей на вершине стека **operationsStack**. Тогда все операции из стека **operationsStack** перекладываются в стек **result**, пока на вершине стека **operationsStack** не будет лежать операция с приоритетом ниже текущей, либо пока стек **operationsStack** не станет пуст;
	* По окончании цикла все операции из стека **operationsStack** перекладываются в стек **result**
	* Стек переписывается в строку. Функция завершает работу

####Подсчет выражения в постфиксной форме
#####Описание метода ***VariableType calculate (const string&, map<char, VariableType>&)***

1. Создается стек, содержащий элементы вещественного типа
2. Выражение просматривается в цикле слева направо. При этом возможны две ситуации:
	* Встретился операнд. Тогда от пользователя запрашивается значение(если оно не запрашивалось ранее, или не было передано в ассоциативном массиве в функцию) и добавляется на вершину стека **result**
	* Встретилась операция. Тогда из стека вынимается один перанд. Затем возможны два случая:
		* Стек **result** стал пуст, тогда встреченная операция - унарный минус. Тогда в стек кладется вынутое значение с противоположным знаком
		* Стек **result** не стал пустым. Тогда из него вынимается еще один элемент. Над элементами совершается действие, описываемое операцией. Результат кладется обратно в стек **result**
3. По окончании работы цикла в стеке будет находиться лишь одно значение. Это значение и будет результатом вычисления выражения

##Заключение
В ходе лабораторной работы были реализованы структуры данных "список" и "стек" с использованием шаблонных классов, так как этого требовали алгоритмы, использующие стек. Написаны приложения, демонстрирующие работу основных методов указанных структур данных. Также написано тестирующее приложение, которое покрывает все методы, используемые в указанных классах (Все теслы успешно пройдены). Реализован алгоритм перевода арифметического выражения из инфиксной вормы в постфиксную, а также алгоритм вычисления значения выражения по существующей польской записи. Написано консольное приложение, демонстрирующее перевод арифметического выражения из инфиксной формы в постфиксную и вычисляющее значение переведенного выражения.

##Литература
1. Павловская Т.А. C/C++. Программирование на языке высокого уровня. - СПб.: Питер. - 2003. - 460с.
2. Шилдт Г. Справочник программиста по C/C++, 3-е издание. М.: "Вильямс", 2006. - 432с.
