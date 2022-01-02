#include <iostream>
#include <torch/torch.h>

using namespace torch;
using namespace std;

int main() {
    cout << "LibTorch version: "<< TORCH_VERSION_MAJOR<<"."
    <<TORCH_VERSION_MINOR<<"."
    <<TORCH_VERSION_PATCH<<"\n"<<endl;

    torch::Device device = torch::kCPU;

    // Generate a tensor
    torch::Tensor tensor = torch::rand({2, 3}).to(device);
    cout << "The following tensor is generated by "<< tensor.device() << endl;
    std::cout << tensor<<"\n" << std::endl;

    // print availability of CUDA, cuDNN and the number of devices supporting CUDA
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
        cout << "This system has "<<torch::cuda::device_count()<<" CUDA-capable device(s)."<<"\n" << endl;

        // Generate one cuda tensor on each GPU
        for (size_t cuda_device_idx = 0; cuda_device_idx < torch::cuda::device_count(); cuda_device_idx++)
        {
            device=torch::Device(torch::kCUDA, cuda_device_idx);
            torch::Tensor cuda_tensor = torch::rand({2, 3}).to(device);
            cout << "The following tensor is generated by "<< cuda_tensor.device() << endl;
            std::cout << cuda_tensor<<"\n" << std::endl;
        }       
    }
    else{
        cout << "False" << endl;
    }  
    return 0;
}