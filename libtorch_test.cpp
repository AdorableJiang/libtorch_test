#include <iostream>
#include <torch/torch.h>    // libtorch头文件

using namespace torch;  // libtorch命名空间
using namespace std;

int main() {
    // 分别打印CUDA、cuDNN是否可用以及可用的CUDA设备个数
    // 可以发现函数名是和PyTorch里一样的
    cout<<"CUDA availability:";
    if(torch::cuda::is_available()){
        cout<<"True"<<endl;
        cout<<"cuDNN availability:";
        if(torch::cuda::cudnn_is_available()){
            cout<<"True"<<endl;
        }
        else{
            cout << "False" << endl;
        }
        //print #GPU
        cout << "This device has "<<torch::cuda::device_count()<<" GPU(s)" << endl;
    }
    else{
        cout << "False" << endl;
    }  
    
    cout << "LibTorch version: "<< TORCH_VERSION_MAJOR<<"."
    <<TORCH_VERSION_MINOR<<"."
    <<TORCH_VERSION_PATCH<<endl;
    return 0;
}