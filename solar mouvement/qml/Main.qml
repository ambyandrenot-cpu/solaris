import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
ApplicationWindow { visible:true; width:1200; height:760; title:"SOLARIS — Simulation solaire"
 property real a: Math.max(-1, Math.min(1, solar.sun.altitude/90))
 background: Rectangle { gradient: Gradient { GradientStop { position:0; color: solar.sun.phase === "Night" ? "#07132f" : solar.sun.phase === "Twilight" ? "#542b62" : "#55a9d5" } GradientStop { position:1; color: solar.sun.phase === "Night" ? "#172348" : solar.sun.phase === "Twilight" ? "#e47b62" : "#f5c77b" } } }
 Rectangle { anchors.fill:parent; color:"transparent"
  Repeater { model: solar.sun.phase === "Night" ? 90 : 0; delegate: Rectangle { width:2;height:2;color:"#fff"; x: (index*97)%parent.width; y:(index*47)%parent.height*0.65; radius:2 } }
  // Voile atmosphérique et étoiles qui disparaissent progressivement avec la lumière.
  Rectangle { anchors.fill: parent; color: "#f7a55a"; opacity: Math.max(0, Math.min(0.22, (6-solar.sun.altitude)/35)) }
  Repeater { model: 28; delegate: Rectangle { width: 2 + index%2; height: width; radius: width/2; color: "#ffffff"; opacity: Math.max(0, Math.min(0.85, (-solar.sun.altitude-2)/18)); x:(index*137+31)%parent.width; y:(index*71+18)%(parent.height*0.62) } }
  Text { anchors.top:parent.top; anchors.left:parent.left; anchors.margins:28; text:"SOLARIS"; color:"white"; font.pixelSize:28; font.bold:true }
  Text { anchors.top:parent.top; anchors.right:parent.right; anchors.margins:30; text:Qt.formatDateTime(solar.dateTime,"ddd dd MMM yyyy  •  HH:mm:ss") + "\n" + solar.sun.phase; color:"white"; horizontalAlignment:Text.AlignRight; font.pixelSize:16 }
  Rectangle { id:info; visible:true; anchors.top:parent.top; anchors.topMargin:100; anchors.left:parent.left; anchors.margins:28; width:245; height:150; radius:14; color:"#101827bb"; Column { anchors.fill:parent; anchors.margins:15; spacing:7; Text{text:"INFORMATIONS SOLAIRES";color:"#ffd36a";font.bold:true} Text{text:"Altitude : "+solar.sun.altitude.toFixed(2)+"°";color:"white"} Text{text:"Azimut : "+solar.sun.azimuth.toFixed(2)+"°";color:"white"} Text{text:"Lever : "+solar.sunrise+"   Coucher : "+solar.sunset;color:"white"} Text{text:"Position : "+solar.latitude.toFixed(2)+"°, "+solar.longitude.toFixed(2)+"°";color:"white"} } }
  Rectangle { width:parent.width; height:parent.height*0.28; anchors.bottom:controls.top; color:"#142d35"; opacity:.95; }
  Item { id:sunFx; width:180; height:180; x:solar.sun.x*parent.width-width/2; y:(1-solar.sun.y)*parent.height*.62-height/2
    Repeater { model: 5; delegate: Rectangle { anchors.centerIn:parent; width:55+index*28; height:width; radius:width/2; color:"#ffca62"; opacity:(0.16-index*0.025)*Math.max(0.15, Math.min(1, (solar.sun.altitude+8)/45)); } }
    Rectangle { id:orb; anchors.centerIn:parent; width:Math.max(34, 52+solar.sun.altitude/4); height:width; radius:width/2; color:"#ffd36a"; border.color:"#fff2bc"; border.width:3; }
  }
  // Nuages stylisés, volontairement peu nombreux pour préserver la fluidité.
  Repeater { model: 4; delegate: Item { width:150+index*25; height:34; x:(index*280+80)%parent.width; y:parent.height*(0.23+index*0.07); opacity:0.12; Row { anchors.fill:parent; spacing:-18; Repeater { model:4; delegate: Rectangle { width:55+index*8; height:24+index*4; radius:30; color:"#ffffff" } } } NumberAnimation on x { from:-180; to:parent.width+180; duration:42000+index*9000; loops:Animation.Infinite } } }
  // Trois plans de paysage pour donner de la profondeur à l'horizon.
  Canvas { anchors.bottom:controls.top; width:parent.width; height:parent.height*0.30; opacity:0.95; onPaint: { var c=getContext("2d"); c.clearRect(0,0,width,height); c.fillStyle="#25484b"; c.beginPath(); c.moveTo(0,height); c.lineTo(0,height*.58); for(var i=0;i<12;i++) c.lineTo(width*i/11,height*(.40+.18*((i*7)%3)/3)); c.lineTo(width,height); c.fill(); } }
  Canvas { anchors.bottom:controls.top; width:parent.width; height:parent.height*0.22; opacity:1; onPaint: { var c=getContext("2d"); c.clearRect(0,0,width,height); c.fillStyle="#142e38"; c.beginPath(); c.moveTo(0,height); c.lineTo(0,height*.42); for(var i=0;i<16;i++) c.lineTo(width*i/15,height*(.28+.20*((i*5)%4)/4)); c.lineTo(width,height); c.fill(); } }
  Rectangle { id:controls; anchors.bottom:parent.bottom; width:parent.width; height:164; color:"#101827dd"; ColumnLayout { anchors.fill:parent; anchors.margins:18; RowLayout { Layout.fillWidth:true; Button { text:solar.running ? "Pause" : "Lecture"; onClicked:solar.pauseResume() } Button{text:"⟲ Réel";onClicked:solar.realTime()} Button{text:"− 1 h";onClicked:solar.advance(-60)} Button{text:"+ 1 h";onClicked:solar.advance(60)} Button{text:"Lever";onClicked:solar.sunriseTime()} Button{text:"Midi";onClicked:solar.solarNoon()} Button{text:"Coucher";onClicked:solar.sunsetTime()} Label{text:"Vitesse";color:"white"} Slider{from:0;to:3600;value:solar.speed;Layout.preferredWidth:180;onMoved:solar.setSpeed(value)} Label{text:solar.speed.toFixed(0)+"×";color:"white"} }
    RowLayout { Layout.fillWidth:true; Label{text:"00:00";color:"white"} Slider{from:0;to:1439;value:solar.minuteOfDay;Layout.fillWidth:true;onMoved:solar.setMinuteOfDay(value)} Label{text:"23:59";color:"white"} }
    RowLayout { Label{text:"Latitude";color:"white"} SpinBox{from:-90;to:90;value:solar.latitude;onValueModified:solar.setLatitude(value)} Label{text:"Longitude";color:"white"} SpinBox{from:-180;to:180;value:solar.longitude;onValueModified:solar.setLongitude(value)} Label{text:"Altitude "+solar.sun.altitude.toFixed(1)+"°   Azimut "+solar.sun.azimuth.toFixed(1)+"°";color:"#d5e8ff"} }
  } }
 }
}
