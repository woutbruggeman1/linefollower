# Instructable

Een instructable is een stappenplan - zonder verdere uitleg - hoe je vertrekkend van de bill of materials en gebruik makend van de technische tekeningen de robot kan nabouwen. Ook de nodige stappen om de microcontroller te compileren en te uploaden staan beschreven.  

##Stap 1: Bestel alle componenten uit de Bill of Materials.

##Stap 2: Componenten afzonderlijk testen.
Test elke component afzonderlijk (motoren, sensor, H-brug, microcontroller, voeding) om zeker te zijn dat alles werkt voordat je begint met de montage.

##Stap 3: PCB layout voorbereiden.
Leg alle onderdelen op de PCB om te controleren of alles past en of de kabelroutes logisch zijn.

##Stap 4: Gaten boren.
Boor de gaten voor de motorhouders met een boor van 2.5 mm.

##Stap 5: Sensor monteren en bedraden.
Solderen van de sensor op de PCB.
Aan de sensoren soldeer je de draden die naar de microcontroller of H-brug gaan.

##Stap 6: Motoren monteren.
Monteer en schroef de motoren vast in de motorhouders op de PCB.

##Stap 7: Microcontroller bevestigen.
Lijm de microcontroller op de batterijhouder en monteer deze batterijhouder op de PCB.

##Stap 8: Breadboard plaatsen.
Bevestig het breadboard op de PCB.
Hierop komen de Bluetooth-module, de H-brug en eventuele knoppen.

##Stap 9: Elektrische aansluitingen maken.
Sluit alle componenten aan volgens het elektrisch schema.
Zorg dat alle ground verbindingen correct gelegd zijn.

##Stap 10: Eerste functionele test.
Controleer of de microcontroller opstart, of de H-brug werkt en of de motoren reageren.

##Stap 11: Zwart/wit kalibratie van de sensor.
Plaats de robot eerst op wit en lees de waarden in als wit-referentie.
Plaats daarna op zwart en sla deze waarden op als zwart-referentie.
Hiermee berekent de robot automatisch thresholds voor lijnvolging.

##Stap 12: Parameters instellen en verdere testen.
Pas de parameters (zoals threshold of PID) aan op basis van de gemeten waarden.
Test de robot op lage snelheid op een eenvoudig parcours.
Verhoog de snelheid wanneer de robot stabiel rijdt.

##Stap 13: Eindtest.
Laat de robot het volledige parcours volgen en controleer of de lijnvolging consistent werkt.
Stel indien nodig nog kleine correcties in.
