#include <iostream>
using namespace std;

void insert_first(int array[], int& range, int first_value) {
    
    for (int i = range; i > 0; --i) {
        array[i] = array[i - 1];
    }
    range++;
    array[0] = first_value;
}

void insert_middle(int array[], int& range, int second_value, int position) {
    
    for (int i = range; i > position; --i) {
        array[i] = array[i - 1];
    }
    range++;
    array[position] = second_value;
}

void insert_last(int array[], int& range, int third_value)
{
	array[range]=third_value;
	range++;
}

void print_array(int array[], int range) {
    for (int i = 0; i < range; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void delete_first(int array[],int& range)
{
	for(int i=0;i<range;i++)
	{
		array[i]=array[i+1];
	}
	range--;
	
}

void delete_middle(int array[],int& range,int position)
{
	for(int i=position;i<range;i++)
	{
		array[i]=array[i+1];
	}
	range--;
}

void delete_end(int array[],int& range)
{
	range--;
}




int main() {
    int range;
    cout << "Enter the range: ";
    cin >> range;
    cout << endl;

    int array[100]; 
    

    for (int i = 0; i < range; ++i) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> array[i];
        
    }
    cout << endl;

    int first_value;
    cout << "Enter the value to be inserted first: ";
    cin >> first_value;
	insert_first(array, range, first_value);
    print_array(array, range);
    
    

   int position, second_value;
    cout << "Enter the position and value to be inserted  : ";
    cin >> position >> second_value ;
	insert_middle(array, range, second_value, position);
    print_array(array, range);
    
    
    int third_value;
    cout << "Enter the value to be inserted last: ";
    cin >> third_value;
    insert_last(array, range, third_value);
    print_array(array, range);
    
    
    cout << "Deletion at first: ";
    delete_first(array, range);
    print_array(array, range);
    
    cout << "Deletion at middle: ";
    delete_middle(array, range,position);
    print_array(array, range);
    
    
    cout << "Deletion at end: ";
    delete_end(array, range);
    print_array(array, range);
    

    return 0;
}

