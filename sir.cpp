#include<iostream>
#include<vector>
#include<cmath>
#include"matplotlibcpp.h"

using namespace sciplot;

void sirModel(float s0, float i0, float r0, float a, float b, int n, std::vector<float>& sv, std::vector<float>& iv, std::vector<float>& rv){
    
    if(n>200){
        return;
    }
    
    float sn = s0 - (a*s0*i0);
    float rn = r0 + (b*i0);
    float in = i0 + (a*s0*i0) - b*i0;

    //std::cout << round(sn) << "\t" << round(in) << "\t" << round(rn) << std::endl;
    sv.push_back(round(sn));
    iv.push_back(round(in));
    rv.push_back(round(rn));

    sirModel(sn, in, rn, a, b, n+1, sv, iv, rv);
}

int main(int argc, char** argv){

    std::vector<float> sv;
    std::vector<float> iv;
    std::vector<float> rv;
    std::vector<float> days;

    for(int i=0;i<200;i++){
        days.push_back(i);
    }

    sirModel(999, 1, 0, 0.0002, 0.083, 0, sv, iv, rv);

    /*for(auto i : iv){
        std::cout << i << std::endl;
    }*/

    return 0;
}