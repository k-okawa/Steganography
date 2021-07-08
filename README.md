# 環境構築
## OpenCV
cmakeがインストールされていない場合はインストール
```shell
brew install cmake
```

OpenCVをインストール
```shell
git clone git@github.com:Itseez/opencv.git
cd opencv
mkdir release
cd release
cmake  ../
make
make install
```

CmakeListに以下を記述すれば読み込める
```cmake
find_package(OpenCV REQUIRED)
target_link_libraries(Steganography ${OpenCV_LIBS})
```