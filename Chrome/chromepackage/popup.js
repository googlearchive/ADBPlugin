
if (navigator.userAgent.match(/Windows NT/))
  document.body.classList.add('platform-windows');
else if (navigator.userAgent.match(/Mac OS X/))
  document.body.classList.add('platform-mac');
else if (navigator.userAgent.match(/Linux/))
  document.body.classList.add('platform-linux');


var devices = document.querySelectorAll('.devices');
var help = document.getElementById('help');

// inspect devices
[].forEach.call( devices, function(elem){

  elem.addEventListener('click', function () {

    chrome.extension.getBackgroundPage().devices();
    window.close();

  }, false);

});

// help
help.addEventListener('click', function () {
  chrome.extension.getBackgroundPage().help();
  window.close();
}, false);

help.addEventListener('click', function () {
  chrome.extension.getBackgroundPage().help();
  window.close();
}, false);
