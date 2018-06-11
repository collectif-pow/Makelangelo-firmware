# POW Robot

Inspired by http://www.makelangelo.com/

## Install

`pio run -e mega -t upload`

## Hardware

* [Nema 17](https://www.amazon.fr/gp/product/B06XQWMDWT/ref=oh_aui_detailpage_o04_s00?ie=UTF8&psc=1) motors
* [Ramps 1.4 board](https://www.amazon.fr/gp/product/B06XPST1SY/ref=oh_aui_detailpage_o01_s00?ie=UTF8&psc=1)
* [GT pulley and belt](https://www.amazon.fr/gp/product/B076H459L6)
* [3D printed parts](https://www.thingiverse.com/thing:1484237)
* [SG 90 servo motor](https://www.amazon.fr/Hrph-Moteur-Helicopter-Contr%C3%B4le-Voiture/dp/B01HZ8NBIC/ref=sr_1_1?ie=UTF8&qid=1516186547&sr=8-1&keywords=servo+moteur+sg90)
* 12v/3A power supply

## Specs

* 200 steps, 16 micro steps
* 20 tooth pulley, 2mm pitch

## Software

Running with [Makelangelo Software](https://github.com/MarginallyClever/Makelangelo-software)

## Settings

* Machine width: 1120,0 mm
* Machine height: 1743,0 mm
* Acceleration: 500
* Max speed: 500 (slow but precise) - 1500 (faster with a bit of jitter)
* Draw speed: 500 (slow but precise) - 1500 (faster with a bit of jitter)
* Pen up: 90,0
* Pen down: 135,0
* Lift delay: 50,0
