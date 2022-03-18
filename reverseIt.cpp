#include<iostream>
#include<fstream>
#include<string>

#define COUNT 50
#define MAX_SIZE 255

using namespace std;

struct IntStack{
    private:
    int *elements=new int[MAX_SIZE];
    int size=-1;
    public:
    void push (int element){
        if(size<MAX_SIZE){
        size++;
        elements[size]=element;
        }
    }
    void pop(){
        if(size>-1){
        size--;
        }
    }
    int top(){
        return elements[size];
    }

    bool isEmpty(){
        if(!elements){
            return true;
        }

        if(size==-1){
            return true;
        }

       return false;
    }

    size_t getSize(){
        return size+1;
    }
    
    void free(){
        delete[] elements;
    }
};

void swap(int &a,int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(){
    IntStack stack;

    int arrayOfNumbers[MAX_SIZE];
    
    for(int i=0;i<COUNT;i++){
        arrayOfNumbers[i]=COUNT-i;
    }
    
    ofstream output_file_stream("numbers.bin",ios_base::binary );
    if(!output_file_stream.is_open()){
        cerr<<"File could not open.";
        return 1;
    }    
    output_file_stream.write((const char*)arrayOfNumbers,COUNT*sizeof(int));
    
    output_file_stream.close();

    int arrayNumbersDisplay[MAX_SIZE];
    ifstream input_file_stream("numbers.bin",ios_base::binary);
      if(!input_file_stream.is_open()){
        cerr<<"File could not open.";
        return 1;
    } 

    input_file_stream.read((char*)arrayNumbersDisplay,COUNT*sizeof(int));
   
    input_file_stream.close();

    for(int i=0;i<COUNT;i++){
        stack.push(arrayNumbersDisplay[i]);
    }

    ofstream textfile_output("textNumbers.txt");

    if(!textfile_output.is_open()){
        return 1;
    }

    while(!stack.isEmpty()){
        textfile_output<<stack.top()<<" ";
        stack.pop();
    }

    textfile_output.close();

  
    stack.free();
    return 0;
}