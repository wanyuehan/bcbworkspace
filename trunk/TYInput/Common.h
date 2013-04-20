#ifndef CommonH
#define CommonH
const int MaxFlag[5]={false,true,true,true,false};
const AnsiString Masks[4]={"00.00;1;_","00.00;1;_","000;1;_","00;1;_"};
const AnsiString Formatstr[4]={"00.00","00.00","000","00"};
const int Choice[6]={12,13,14,23,24,34};
const int ChoiceCount=6;
const AnsiString Subjects[4]={"50米","投实心球","跳绳","垫排球"};
const UnicodeString ChoiceStr[6]={
	"50米+投实心球",
	"50米+跳绳",
	"50米+垫排球",
	"投实心球+跳绳",
	"投实心球+垫排球",
	"跳绳+垫排球"
};
#endif
