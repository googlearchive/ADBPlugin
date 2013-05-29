var start = document.getElementById('start'),
    stop  = document.getElementById('stop'),
   plugin = chrome.extension.getBackgroundPage(),
  devices = document.getElementById('devices'),
  forward = document.getElementById('forward'),
     note = document.getElementById('note'),
     form = document.getElementById('form'),
formCancel = form.querySelector('input[type="reset"]');

if (plugin.isServerRunning()) {
  start.classList.add('disabled');
} else {
  devices.classList.add('disabled');
  stop.classList.add('disabled');
  forward.classList.add('disabled');
  form.querySelector('input[type="submit"]').disabled = true;
  form.querySelector('input[type="reset"]').disabled = true;
  form.querySelector('input[name="port"]').disabled = true;
}

if (plugin.getCurrentPort()) {
  form.querySelector('input[type="submit"]').disabled = true;
  form.querySelector('input[name="port"]').disabled = true;
  form.querySelector('input[name="port"]').value = plugin.getCurrentPort();
}

devices.addEventListener('click', function () {
  if (devices.classList.contains('disabled'))
    return;
  plugin.devices();
  window.close();
}, false);

start.addEventListener('click', function () {
  if (start.classList.contains('disabled'))
    return;
  plugin.start();
  window.close();
}, false);

stop.addEventListener('click', function () {
  if (stop.classList.contains('disabled'))
    return;
  plugin.stop();
  window.close();
}, false);
forward.querySelector('input[name="port"]').oninvalid = function() {
  document.querySelector('#note').classList.remove('hidden');
  setTimeout(function(){ note.classList.add('hidden');}, 1500);
  return false;
};
note.addEventListener('click', function(){ note.classList.add('hidden');});

form.onsubmit = function() {
  var port = this.querySelector('input[name="port"]').value
  if (port) {
    this.querySelector('input[type="submit"]').disabled = true;
    this.querySelector('input[name="port"]').disabled = true;
    plugin.forward(port);
  }
  return false;
};

form.onreset = function(){
  if (form.querySelector('input[name="port"]').disabled) {
    form.querySelector('input[type="submit"]').disabled = false;
    form.querySelector('input[name="port"]').disabled = false;
    form.querySelector('input[name="port"]').focus();
    return false;
  } else {
    return true;
  }
};
