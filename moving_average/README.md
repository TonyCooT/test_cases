
## Алгоритм Simple Moving Average

Алгоритм используется для анализа данных путем вычисления серии средних значений различных выборок из полного набора данных.
Параметром алгоритма является размер выборки

### Данные производительности

Оценка производительности алгоритма производится на данных типа `float` и `double`.
Размер набора данных равен 1000000 значений.
Значение размера выборки берется из следующего диапазона: 4, 8, 16, 32, 64, 128

Конфигурация оборудования:
* Центральный процессор - Intel Core i5-6200U@2.3GHz
* Оперативная память - 8Gb DDR4
* Операционная система - Windows 10 x64

Для каждого сочетания условий производится 5 прогонов. Результаты анализа приведены в графическом виде ниже

![](https://github.com/TonyCooT/test_cases/blob/main/moving_average/.images/chart_float.png)

![](https://github.com/TonyCooT/test_cases/blob/main/moving_average/.images/chart_double.png)

![](https://github.com/TonyCooT/test_cases/blob/main/moving_average/.images/chart_comparison.png)
