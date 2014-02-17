
if (navigator.userAgent.match(/Windows NT/))
  document.body.classList.add('platform-windows');
else if (navigator.userAgent.match(/Mac OS X/))
  document.body.classList.add('platform-mac');
else if (navigator.userAgent.match(/Linux/))
  document.body.classList.add('platform-linux');


var devices = document.getElementById('devices');

devices.addEventListener('click', function () {

  chrome.extension.getBackgroundPage().devices();
  window.close();

}, false);
