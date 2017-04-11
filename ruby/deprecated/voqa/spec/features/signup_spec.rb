require 'rails_helper'

RSpec.feature "User Registration" do 
  scenario "allows a user to sign up" do
    visit 'users/sign_up'

    fill_in "user_email", with: Faker::Internet.email 
    fill_in "password", with: "password"
    fill_in "user_password_confirmation", with: "password"
    click_button "Sign Up"

    expect(page).to have_text("Welcome! You have signed up successfully.")

  end
end

