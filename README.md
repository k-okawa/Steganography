# SteganographySample
ステガノグラフィのサンプルです

## ビルド

```
cmake ./
make
```

## 実行
### 文字列画像埋め込み

```
./Steganography --test strInsert --img ./assets/icon.png --str hello_steganography --out ./assets/out.png
```

### Luaスクリプト画像埋め込み

```
./Steganography --test lua --img ./assets/icon.png --path ./assets/luaScript.lua --out ./assets/out.png
```

### 自作言語スクリプト画像埋め込み

```
./Steganography --test myParser --img ./assets/icon.png --path ./assets/myScript.bs --out ./assets/out.png
```

## 実装メモ
### OpenCV
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

### Lua
#### C++でのLuaの扱い参考
https://qiita.com/hiz_/items/8739c46ddd2563a5603f

### Flex, Bison
#### インストール
```shell
brew install flex bison
```

homebrewでインストールしたbison,flexのバージョンに変更する
```shell
brew link flex --force
brew link bison --force
```

#### flexビルド

flex 2.6.4

```shell
flex -o PlnLexer.cpp lexer.l
```

ビルドした後、PlnLexer.cppのincludeを変える

304行目

#include <FlexLexer.h> → #include "PlnLexer.h"

#### bisonビルド

bison (GNU Bison) 3.7.6

```shell
bison -o PlnParser.cpp -r all --report-file=bison.log parser.y
```

C++はこちらを参考にしてみる
https://github.com/tosyama/palan/tree/master/src/ast