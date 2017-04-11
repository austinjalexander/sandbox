# Place all the behaviors and hooks related to the matching controller here.
# All this logic will automatically be available in application.js.
# You can use CoffeeScript in this file: http://coffeescript.org/

$('#cancel_answer').click (e) ->
  e.preventDefault()
  $("#answer_button").trigger 'click'
  return

$('#answer_submit').click (e) ->
  $("#answer_button").trigger 'click'
  return