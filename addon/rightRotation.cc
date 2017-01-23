#include <node.h>
#include <stdio.h>
#include <stdlib.h>

void displayMatrix(unsigned int const *p,
  unsigned int row,
  unsigned int col);
void rotate(unsigned int *pS, unsigned int *pD,
  unsigned int row, unsigned int col);

    void displayMatrix(unsigned int const *p,
                       unsigned int r,
                       unsigned int c)
    {
        unsigned int row, col;
        printf("\n\n");

        for (row = 0; row < r; row++)
        {
            for (col = 0; col < c; col++)
                printf("%d\t", *(p + row * c + col));
            printf("\n");
        }

        printf("\n\n");
    }

    void rotate(unsigned int *pS, unsigned int *pD,
                unsigned int row, unsigned int col)
    {
        unsigned int r, c;
        for (r = 0; r < row; r++)
        {
            for (c = 0; c < col; c++)
            {
                *(pD + c * row + (row - r - 1)) =
                                *(pS + r * col + c);
            }
        }
    }

namespace demo {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Array;
using v8::Handle;

using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Number;
using v8::Object;
using v8::String;

void Add(const v8::FunctionCallbackInfo<v8::Value>&args) {
    Isolate* isolate = args.GetIsolate();

    if (args.Length() < 2) {
      // Throw an Error that is passed back to JavaScript
      isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Wrong number of arguments")));
      return;
    }

    // Check the argument types
    if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
      isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Wrong arguments")));
      return;
    }

    // Perform the operation
    double value = args[0]->NumberValue() + args[1]->NumberValue();
    Local<Number> num = Number::New(isolate, value);

    args.GetReturnValue().Set(num);
  }

  // void init(Local<Object> exports) {
  //   NODE_SET_METHOD(exports, "add", Add);
  // }

void Rotate(const v8::FunctionCallbackInfo<v8::Value>&args) {
  Isolate* isolate = args.GetIsolate();

   //
   Local<Array> input = Local<Array>::Cast(args[0]);
   unsigned int num_locations = input->Length();


   unsigned int image[][4] = {{1,2,3,4},
   {5,6,7,8},
   {9,10,11,12}};
   unsigned int *pSource;
   unsigned int *pDestination;
   unsigned int m, n;

   // setting initial values and memory allocation
   m = 3, n = 4, pSource = (unsigned int *)image;
   pDestination =
   (unsigned int *)malloc(sizeof(int)*m*n);

   displayMatrix(pSource, m, n);

   rotate(pSource, pDestination, m, n);

   displayMatrix(pDestination, n, m);

   free(pDestination);

   getchar();

   Handle<v8::Array> result = Array::New(e1.size());
   for (size_t i = 0; i < e1.size(); i++)
    result->Set(i, num_locations);

  args.GetReturnValue().Set(Array::New(isolate, num_locations));
  // return num_locations;
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "rightRotation", Rotate);
  NODE_SET_METHOD(exports, "add", Add);

}

NODE_MODULE(rightRotation, init)

}  // namespace demo
