#include "pch.h"
#include<iostream>

extern "C" {
#include "libavcodec/avcodec.h";
#include "libsdl/SDL.h"
}
int main()
{
	using namespace std;
	std::printf("%s", avcodec_configuration());
}