# esy-inverted-ctypes-stubs


[![CircleCI](https://circleci.com/gh/yourgithubhandle/esy-inverted-ctypes-stubs/tree/master.svg?style=svg)](https://circleci.com/gh/yourgithubhandle/esy-inverted-ctypes-stubs/tree/master)


**Contains the following libraries and executables:**

```
esy-inverted-ctypes-stubs@0.0.0
│
├─test/
│   name:    TestEsyInvertedCtypesStubs.exe
│   require: esy-inverted-ctypes-stubs/library
│
├─library/
│   library name: esy-inverted-ctypes-stubs/library
│   require:
│
└─executable/
    name:    EsyInvertedCtypesStubsApp.exe
    require: esy-inverted-ctypes-stubs/library
```

## Developing:

```
npm install -g esy
git clone <this-repo>
esy install
esy build
```

## Running Binary:

After building the project, you can run the main binary that is produced.

```
esy x EsyInvertedCtypesStubsApp.exe 
```

## Running Tests:

```
# Runs the "test" command in `package.json`.
esy test
```
