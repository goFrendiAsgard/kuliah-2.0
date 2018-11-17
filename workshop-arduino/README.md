# Electricity

Electricity is simply defined as movement of electrons.

Almost everything we know is consists of atoms. And inside the atoms there are 3 sub-atomic particles, `proton` (+), `neutron`, and `electron` (-). Electrons can move from one atom to another.

[!Atom Structure](atom.jpeg)

## Charge (q)

Electricity charge appeared when the amount of protons and electrons is not equal. The greater the difference, the greater the electricity charge.

The symbol of electricity charge is `q`, while it's unit is `coulomb`

## Current (I)

Current is the rate at which charge is flowing (`I = q/t`).

The symbol of current is `I`, while it's unit is `ampere`.

## Voltage (V)

Voltage is the difference in charge between two points. This difference is the reason why electricity exists.

## Resistance (R)

Resitance is a material’s tendency to resist the flow of charge (current).

[!Waterfall](waterfall.jpeg)

## Parallel vs Series

[!Series vs Parallel](series-and-parallel-circuits.jpg)

## Short Circuit (beware)

[!Short circuit](short-circuit.jpeg)

# Arduino

Easy-to-use micro-controller board

## How it works

```
[Anything] ----> [Sensor] ---electricity---> [Arduino] ---electricity---> [Actuator] ----> [Anything]
```

[!input-output-process](input-output-process.png)

## Arduino program

[!Program](arduino-program.jpeg)

## The circuit

[!circuit](circuit.png)

## Example: Blink

```c
void setup() {
  pinMode(13, OUTPUT);       // Connect pin-13 to LED
}

void loop() {
  digitalWrite(13, HIGH);    // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(13, LOW);     // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
```

## Example: Push Button

```c
void setup() {
  pinMode(12, INPUT);        // Connect pin-12 to push-button
  pinMode(13, OUTPUT);       // Connect pin-13 to LED
}

void loop() {
  int pressed = digitalRead(12);  // if someone press the button, `pressed` will be HIGH, otherwise it is going to be LOW
  if (pressed == HIGH) {
    digitalWrite(13, HIGH);       // Someone press the button, turn the LED on
  } else {
    digitalWrite(13, LOW);        // button is not pressed, turn the LED off
  }
}
```

## Example: Push Button (Simple)

```c
void setup() {
  pinMode(12, INPUT);        // Connect pin-12 to push-button
  pinMode(13, OUTPUT);       // Connect pin-13 to LED
}

void loop() {
  digitalWrite(13, digitalRead(12));
}
```


## Example: Push Button (With state)

```c
int state = 0;
void setup() {
  pinMode(12, INPUT);        // Connect pin-12 to push-button
  pinMode(13, OUTPUT);       // Connect pin-13 to LED
}

void loop() {
  int pressed = digitalRead(12);  // if someone press the button, `pressed` will be HIGH, otherwise it is going to be LOW
  if (pressed == HIGH) {
    if (state == 0) {             // if button is pressed and state = 0, change state to 1
        state = 1;
    } else {                      // if button is pressed and state = 1, change state to 0
        state = 0
    }
  }
  digitalWrite(13, state);        // turn on/off LED based on state's value
}
```

