# soloud-web
A web wrapper for Soloud API (for making sound)

> **WARNING**: this is currently not functional. I need to work out how to wrap things better.

```
git clone --recursive git@github.com:konsumer/soloud-web.git
cd soloud-web
```

## native exe (for testing)

```
cmake -B build
cmake --build build
```

## wasm (for web)

```
emcmake cmake -B build
cmake --build build
```
