# Gebruiksaanwijzing

### opladen / vervangen batterijen
Voorzie de oplader van voeding en steek de batterijen in de oplader. Het opladen is voltooid als het lichtje groen wordt.

### draadloze communicatie
#### verbinding maken
Ik maak gebruik van de HC-05 Bluetooth-module, waarmee verbinding kan worden gemaakt met een Android-smartphone. Op de smartphone moet je eerst "serial bluetooth installeren. Vervolgens verbind je via de Bluetooth-instellingen van de telefoon met de HC-05-module. Daarna open je de app en maak je daar ook verbinding. Zodra dit is voltooid, kun je via de app commando’s sturen naar de robot.

#### commando's
start / zorgt dat de auto begint te rijden

stop / zorgt dat de auto stopt met rijden

set power [0..255] / bepaalt de snelheid van de auto


set kp [0..] / bepaald de kp waarde van de pid regelaar

set ki [0..] / bepaald de ki waarde van de pid regelaar

set kd [0..] / bepaald de kd waarde van de pid regelaar

calibrate / de sensoren worden gekalibreert op de zwarte en witte waarden.]  

### kalibratie
Om de sensor te kalibreren, plaats je deze eerst op een zwart vlak. Via de app op je smartphone geef je vervolgens het commando “calibrate black”. Doe daarna hetzelfde met een wit vlak en geef het commando “calibrate white”.
Als alles correct is uitgevoerd, kun je via het commando “debug” controleren of de kalibratie gelukt is. Bij een wit vlak zie je dan ongeveer 6 lage waarden en bij een zwart vlak ongeveer 2 hoge waarden.

### settings
De robot rijdt stabiel met volgende parameters: power = 30; diff = 0.75; Kp= 1.3; Ki = 0; Kd = 0; cycle = 2000

### start/stop button
starten en stoppen die je opnieuw met serial bluetooth en je moet om te starten het commando run intypen en om te stoppen het commando stop
