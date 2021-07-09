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

## Lua
### C++でのLuaの扱い参考
https://qiita.com/hiz_/items/8739c46ddd2563a5603f

## Flex, Bison
### インストール
```shell
brew install flex bison
```

### flexビルド
```shell
flex -l parser.l
```

### bisonビルド
```shell
bison -dy parser.y
```