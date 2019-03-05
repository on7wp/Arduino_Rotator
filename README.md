# Arduino_Rotator
a low cost DC rotator controller based on cheap chinese modules

I needed a rotator controller as I have some orphan Create and Yaesu SDX800 rotators that both work on DC.
If you google “arduino rotator” then you get tons of articles all based on the K3NG design.  Seriously ??
Although it is a nice realization it is typical for amateur radio applications.  Vintage like hell based on old school technologies.  RELAYS, in 2019 ?   Really ???
So in an afternoon I put something together minimal effort based on a cheap Chinese Arduino, a Chinese LCD keypad shield and a Chinese L298N motor driver module.  All for less than 10 Euro !
Straight forward design: two lines on the display, the first showing the actual rotator position, the second the target position.  You set the target using a 10 turn potmeter.  No other parts are needed, just some wiring.
The rotator will automatically adjust speed when reaching target in three steps.
