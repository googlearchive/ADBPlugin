(function () {
  if (navigator.userAgent.match(/Windows NT/))
    document.body.classList.add('platform-windows');
  else if (navigator.userAgent.match(/Mac OS X/))
    document.body.classList.add('platform-mac');
  else if (navigator.userAgent.match(/Linux/))
    document.body.classList.add('platform-linux');
})();

var devices = document.getElementById('devices');
var start = document.getElementById('start');
var stop = document.getElementById('stop');
var openUrlButton = document.getElementById('openUrlButton');
var help = document.getElementById('help');

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

openUrlButton.addEventListener('click', function () {
  // if (start.classList.contains('disabled'))
  //   return;

  var url = document.getElementById("openUrlInput").value;
  chrome.extension.getBackgroundPage().openUrl(url);
  window.close();
}, false);

help.addEventListener('click', function () {
  chrome.extension.getBackgroundPage().help();
  window.close();
}, false);
