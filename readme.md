<p align="center">
<img src="https://img.shields.io/github/contributors/corruptTeam/corruptOS.svg"/>
<img src="https://img.shields.io/github/forks/corruptTeam/corruptOS.svg"/>
<img src="https://img.shields.io/github/stars/corruptTeam/corruptOS.svg"/>
<img src="https://img.shields.io/github/issues/corruptTeam/corruptOS.svg"/>
<img src="https://github.com/corruptTeam/corruptOS/actions/workflows/build.yml/badge.svg"/>
<img src="https://app.codacy.com/project/badge/Grade/07eccca76af44130928ab52eb2da0800"/>
</p>
  <h3 align="center">corruptKernel</h3>
  <p align="center">
  ⚡ corruptOS | A hobby OS
  <br/>
  <a href="https://github.com/corruptTeam/corruptOS/issues/new?labels=bug">Report a bug</a>
  |
  <a href="https://github.com/corruptTeam/corruptOS/issues/new?labels=feature">Request a feature</a>
  </p>
<br/>

## 📲 Download
### Kernel
You can download latest release [here](https://github.com/corruptTeam/corruptOS/releases)<br/>
Or you can download latest Actions build from [here](https://github.com/corruptTeam/corruptOS/actions)<br/>
### OS
There's no OS option available for now, beacuse kernel is incomplete.
## ❗️ Requirements
### Arch/Arch-based
```sh
sudo pacman -S base-devel qemu make mtools nasm git
```
## ❓ How to run
Run `make norun` to build everything with `corruptOS.img` image file</br>
Run `make all` to build everything and run `corruptOS.img` image file using QEMU (gdb forced)</br>
Run `make nodbg` to build everything and run `corruptOS.img` image file using QEMU (gdb disabled)</br>
Run `make run` to run `corruptOS.img` image file using QEMU (gdb forced)</br>
Run `make run-nogdb` to run `corruptOS.img` image file using QEMU (gdb disabled)
## 📚 Credits
Some kernel stuff: [SteveJ/OSDev](https://github.com/stevej/osdev)</br>
General: [OSDev Wiki](https://wiki.osdev.org)

## 👥 Contributors
[TheAirBlow](https://github.com/theairblow)
