var VERSION = "1.6";

Pebble.addEventListener('ready', function(e) {
  console.log('PebbleKit JS ready! Version: ' + VERSION);
});

Pebble.addEventListener('showConfiguration', function(e) {
  Pebble.openURL('http://mephissto.github.io/thin-config.html');
});

Pebble.addEventListener('webviewclosed', function(e) {
  var json = JSON.parse(decodeURIComponent(e.response));

  var options = {
    "PERSIST_KEY_DATE": '' + json.date,
    "PERSIST_KEY_DAY": '' + json.day,
    "PERSIST_KEY_BT": '' + json.bluetooth,
    "PERSIST_KEY_BATTERY": '' + json.battery,
    "PERSIST_KEY_SECOND_HAND": '' + json.second_hand,
    "PERSIST_KEY_THEME": '' + json.theme
  };
  
  console.log('____________________ Configuration window returned: ' + JSON.stringify(json));

  Pebble.sendAppMessage(options,
    function(e) {
      console.log('Settings update successful!');
    },
    function(e) {
      console.log('Settings update failed: ' + JSON.stringify(e));
    });
}); 