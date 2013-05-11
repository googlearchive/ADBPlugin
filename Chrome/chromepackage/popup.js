var devices = document.getElementById('devices');
var start = document.getElementById('start');
var stop = document.getElementById('stop');

if (chrome.extension.getBackgroundPage().isServerRunning()) {
  start.classList.add('disabled');
} else {
  devices.classList.add('disabled');
  stop.classList.add('disabled');
}

devices.addEventListener('click', function () {
  if (devices.classList.contains('disabled'))
    return;
  chrome.extension.getBackgroundPage().devices();
  window.close();
}, false);

start.addEventListener('click', function () {
  if (start.classList.contains('disabled'))
    return;
  chrome.extension.getBackgroundPage().start();
  window.close();
}, false);

stop.addEventListener('click', function () {
  if (stop.classList.contains('disabled'))
    return;
  chrome.extension.getBackgroundPage().stop();
  window.close();
}, false);
