document.getElementById('devices').addEventListener('click', function () {
  chrome.extension.getBackgroundPage().devices();
  window.close();
}, false);

var start = document.getElementById('start');
var stop = document.getElementById('stop');

if (chrome.extension.getBackgroundPage().isServerRunning())
  start.classList.add('disabled');
else
  stop.classList.add('disabled');

start.addEventListener('click', function () {
  chrome.extension.getBackgroundPage().start();
  window.close();
}, false);

stop.addEventListener('click', function () {
  chrome.extension.getBackgroundPage().stop();
  window.close();
}, false);
