clear

mkdir -p build
cd build

mkdir -p cmake
mkdir -p out
cd cmake

cmake ../../
make

mv fsb ../out
cd ../out

cp ../../config/fsb.config ./fsb.config
chmod +x fsb

echo ""
./fsb
