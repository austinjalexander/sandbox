# Place all the behaviors and hooks related to the matching controller here.
# All this logic will automatically be available in application.js.
# You can use CoffeeScript in this file: http://coffeescript.org/

$('#cancel').click (e) ->
  e.preventDefault()
  $("#ask_button").trigger 'click'
  return

$('#ask_submit').click (e) ->
  $("#ask_button").trigger 'click'
  return

$(document).ready ->

  if $('.pagination').length > 0

    $(window).scroll ->
      next_url = $('.pagination .next_page').attr('href')

      if next_url and ( $(window).scrollTop() > $(document).height() - $(window).height() - 50 )
        $('.pagination').text 'Loading more questions...'
        return $.getScript(next_url)

      if $('.next_page').hasClass('disabled')
        $('.pagination').remove()

    return
  return
