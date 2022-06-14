#include <memory>

struct A
{
	int a;
	int b;
	int c;
};

int main()
{
	std::allocator<A> allocator;
	size_t howMuch = 50;
	// Выделяем память под 50 структур A. Возвращённый указатель, указывает на неинициализированную память.
	A* allocatedArray = allocator.allocate(howMuch);

	A* allocatedItem = allocator.allocate(1);
	// Т.к. память не инициализирована, нам нужно её инициализировать. Для этого вызываем конструктор A явно
	allocator.construct(allocatedItem);
	// Для инициализации памяти под массив есть вспомогательная функция, которая сделает то же самое, что
	// делает allocator по умолчанию
	std::uninitialized_fill_n(allocatedArray, howMuch, A());
	// После того, как наигрались с объектом, его нужно удалить, но сначала нужно вызвать деструктор
	allocator.destroy(allocatedItem);
	for(size_t i = 0; i < howMuch; ++i)
		allocator.destroy(allocatedArray + i);
	// Теперь освобождаем выделенную память
	allocator.deallocate(allocatedItem, 1);
	allocator.deallocate(allocatedArray, howMuch);
	return 0;
}