
# HelloWorld
A simple example for [SideCMake](https://www.github.com/imlinkzuz/sidecmake).

## Clone SideCMake
Clone the SideCMake repository to a directory located alongside SideCMakeExamples:
```
git clone https://www.github.com/imlinkzuz/SideCMake \path\to\SideCMake
```
## Customize Settings
- In `LocalPresets.json`, set the `SIDECMAKE_DIR` variable in the `cacheVariables` section to `\path\to\SideCMake`.
- In `ProjectPresets.json`, set `SC_PROJECT_NAME` to `HelloWorld`. You may adjust other settings as needed.

## Build and Install
```sh
cmake /path/to/HelloWorld --preset default
cd /path/to/HelloWorld/../_build/default
# for release
cmake --build . --target install --config Release
# for debug
cmake --build . --target install --config Debug
```

> [!TIP]
> All installed files will be located in `/path/to/HelloWorld/../_install/default`.

