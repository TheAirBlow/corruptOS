<p align="center">
<img src="https://img.shields.io/github/contributors/NeticTeam/AirKernel.svg"/>
<img src="https://img.shields.io/github/forks/NeticTeam/AirKernel.svg"/>
<img src="https://img.shields.io/github/stars/NeticTeam/AirKernel.svg"/>
<img src="https://img.shields.io/github/issues/NeticTeam/AirKernel.svg"/>
<img src="https://github.com/NeticTeam/AirKernel/actions/workflows/build.yml/badge.svg"/>
<img src="https://app.codacy.com/project/badge/Grade/fd5a7833d434455e8c455fce709f0b78"/>
</p>
  <h3 align="center">AirKernel</h3>
  <p align="center">
  ⚡ AirKernel is an UEFI kernel (UEFI bootloader)
  <br/>
  <a href="https://github.com/NeticTeam/AirKernel/issues/new?labels=bug">Report bug</a>
  |
  <a href="https://github.com/NeticTeam/AirKernel/issues/new?labels=feature">Request a feature</a>
  </p>
<br/>

## 📲 Download
### Kernel
You can download latest release [here](https://github.com/NeticTeam/AirKernel/releases)<br/>
Or you can download latest Actions build from [here](https://github.com/NeticTeam/AirKernel/actions)<br/>
Be sure that it's "dev" not "stable" one, as all really stable versions should be in releases.<br/>
### OS
There's no OS option available for now, beacuse kernel is incomplete.

## Showcase
<a href='https://youtu.be/bhx9Phf49ok'>Click me!</a>

## ❗️ Requirements
### Debian/Debian-based
```sh
sudo apt install gcc g++ qemu qemu-system make mtools nasm git moreutils
```
### Arch/Arch-based
```sh
sudo pacman -S base-devel qemu make mtools nasm git moreutils
```
### Gentoo
```sh
sudo emerge --ask app-emulation/qemu sys-fs/mtools dev-vcs/git dev-lang/nasm sys-apps/moreutils
```

## 💻 Plans

### Memory
- [x] Heap
- [ ] Paging

## ❓ How to run
```sh
make
make run
```

## 📚 Credits
Kernel Base: [PonchoOS](https://github.com/absurdponcho/ponchoos)

Tutorials: [OSDev](https://wiki.osdev.org)

## 👥 Developers
Leader: [z3r0memory](https://github.com/z3r0memory)

Maintainer: [TheAirBlow](https://github.com/theairblow)

