# messing with rp2040
Hi! if you stumbled upon this github repository you might be looking to work with your rp2040 on a lower level or trying to understand how it works.. that's what i was trying to do here!
The code contains nothing special, so here's 
### a few tips:
## my working enviroment
* I'm on debian 11
* i've installed the [pico-sdk 1.5.1](https://github.com/raspberrypi/pico-sdk)
* using regular vscode
* using [cortex-debug vscode extension](https://github.com/Marus/cortex-debug)
## issues
So three things to note:
1. The [guide i initially followed](https://www.digikey.be/en/maker/projects/raspberry-pi-pico-and-rp2040-cc-part-2-debugging-with-vs-code/470abc7efb07432b82c95f6f67f184c0) is old and used deprecated configs and executables so here's an updated config file:
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

2. For whatever reason the svd file provided when you install the pico-sdk doesn't work, at least in my case it doesn't let you mess with the peripherial registers and shows them all as read-only, so you will need to [download](https://github.com/raspberrypi/pico-sdk/blob/master/src/rp2040/hardware_regs/rp2040.svd) this one instead and replace the old one with it ```${env:PICO_SDK_PATH}/src/rp2040/hardware_regs/rp2040.svd```.

3. Make sure to download the [right](https://github.com/raspberrypi/picoprobe/releases/tag/picoprobe-cmsis-v1.0.3) firmware if you're using an rp2040 to debug another rp2040 select the downloads with the name "picoprobe" and not "debugprobe"

## cool resources
- [bitwisecmd](https://bitwisecmd.com/)
- [RP2040 assembly language programming by S. Smith book code repo](https://github.com/Apress/RP2040-Assembly-Language-Programming)
- [Cortex-M0+ generic user guide](https://developer.arm.com/documentation/dui0662/b?lang=en)
- [RP2040 assembly language programming book](https://link.springer.com/chapter/10.1007/978-1-4842-7753-9_6)
