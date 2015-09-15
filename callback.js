Drupal.theme.prototype.salonModalHtml = function () {
  var html = '';
  html += '<div id="ctools-modal" class="salon-modal-custom ctools-modal-custom">';
  html += '  <div class="ctools-modal-content ctools-modal-custom-help-content">';
  html += '    <div class="modal-header">';
  html += '      <span class="popups-close"><a class="close" href="#">' + Drupal.CTools.Modal.currentSettings.closeImage + '</a></span>';
  html += '      <div class="modal-title">Help</div>';
  html += '    </div>';
  html += '    <div class="modal-scroll"><div id="modal-content" class="modal-content modal-content-custom"></div></div>';
  html += '  </div>';
  html += '</div>';
  return html;
}
