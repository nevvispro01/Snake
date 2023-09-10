# How to build

## Server
dependencies:
- first
- second

for build only server:
```sh
cmake -S /path/to/source/ -B /path/to/build -D SNAKE_BUILD_SERVER=ON
cmake --build /path/to/build --target all
```

## Client 

dependencies:
- first
- second

for build only client:
```sh
cmake -S /path/to/source/ -B /path/to/build -D SNAKE_BUILD_CLIENT=ON
cmake --build /path/to/build --target all
```
