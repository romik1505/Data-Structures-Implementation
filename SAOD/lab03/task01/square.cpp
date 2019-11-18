//Сколько квадратов можно отрезать от прямоугольника со сторонами a и в. 

unsigned int square(unsigned int a, unsigned int b)
{
	if (b > a)
		return (square(a, b - a) + 1);
	else if (b < a)
		return (square(a - b, b) + 1);
	return (0);
}