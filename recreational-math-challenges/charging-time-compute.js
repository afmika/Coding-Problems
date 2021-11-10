function Battery (milli_amps, volts_delivered) {
	this.milli_amps = milli_amps;
	this.volts_delivered = volts_delivered;
	this.power = () => (this.milli_amps / 1000 ) * this.volts_delivered;
}

function Charger (milli_amps, volts_delivered) {
	this.milli_amps = milli_amps;
	this.volts_delivered = volts_delivered;
	this.power = () => (this.milli_amps / 1000 ) * this.volts_delivered;
}

function compute (battery, charger) {
	
	return battery.power () / charger.power ();
}



console.log(
	compute (
		new Battery (3000, 3.7), // 3.7V - 3000mA
		new Charger (500, 5) // 5V - 0.5A = 500mA
	)
);