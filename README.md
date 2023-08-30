# messing with rp2040
Hi! if you stumbled upom this github repository you might be looking to work with your rp2040 on a lower level or trying to understand how it works.. that's what i was trying to do here!
## my working enviroment
* I'm on debian 11
* i've installed the pico-sdk
* using regular vscode
* using cortex-debug vscode extension to debug
## issues
So three things to note:
1. The [guide i initially followed](https://www.digikey.be/en/maker/projects/raspberry-pi-pico-and-rp2040-cc-part-2-debugging-with-vs-code/470abc7efb07432b82c95f6f67f184c0) is old and used *arm-none-eabi-gdb*,
in the cortex-debug config you instead need to use *gdb-multiarch*
```js
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Pico Debug",
            "cwd": "${workspaceRoot}",
            "executable": "${command:cmake.launchTargetPath}",
            "request": "launch",
            "type": "cortex-debug",
            "servertype": "openocd",
            // This may need to be arm-none-eabi-gdb depending on your system
            "gdbPath" : "gdb-multiarch",
            "device": "RP2040",
            "configFiles": [
                "interface/cmsis-dap.cfg",
                "target/rp2040.cfg"
            ],
            "openOCDLaunchCommands": ["adapter speed 5000"],
            "svdFile": "${env:PICO_SDK_PATH}/src/rp2040/hardware_regs/rp2040.svd",
            // Work around for stopping at main on restart
            "postRestartCommands": [
                "break main",
                "continue"
            ],
            "searchDir": ["your path to tcl here"],
        }
    ]
}
```

2. For whatever reason the svd file provided when you install the pico-sdk doesn't work, at least in my case it doesn't let you mess with the peripherial registers and shows them all as read-only, so you will need to [download](https://github.com/raspberrypi/pico-sdk/blob/master/src/rp2040/hardware_regs/rp2040.svd) this one instead and replace the old one with it (${env:PICO_SDK_PATH}/src/rp2040/hardware_regs/rp2040.svd).

3. Make sure to download the [right](https://github.com/raspberrypi/picoprobe/releases/tag/picoprobe-cmsis-v1.0.3) firmware if you're using an rp2040 to debug another rp2040 select the downloads with the name "picoprobe" and not "debugprobe"