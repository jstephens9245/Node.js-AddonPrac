#include <node.h>
#include <stdio.h>
#include <stdlib.h>

#include <Magick++.h>
#include <iostream>

using namespace std;
using namespace Magick;

namespace demo {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void Method(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

   //

 // int main(int argc,char **argv)
 // {
     unsigned char pix[]={200,200,200, 100,100,100, 0,0,0, 255,0,0, 0,255,0, 0,0,255};

     // Initialise ImageMagick library
     InitializeMagick(*argv);

     // Create Image object and read in from pixel data above
     Image image;
     image.read(2,3,"RGB",CharPixel,pix);

     // Write the image to a file - change extension if you want a GIF or JPEG
     image.write("result.png");
 // }

  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "finished"));
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "imgRead", Method);
}

NODE_MODULE(imgRead, init)

}  // namespace demo
