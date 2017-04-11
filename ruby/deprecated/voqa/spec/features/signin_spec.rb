require 'rails_helper'

RSpec.feature "User Sign In" do 

  user = FactoryGirl.create(:user)

  scenario "allows a user to sign in" do
    visit 'users/sign_in'

    fill_in "user_email", with: user.email
    fill_in "password", with: user.password
    click_button "Sign In"

    expect(page).to have_text("Signed in successfully.")

  end

  scenario "does not allow a non-registered user to sign in" do
    visit 'users/sign_in'

    fill_in "user_email", with: Faker::Internet.email
    fill_in "password", with: Faker::Internet.password
    click_button "Sign In"

    expect(page).to have_text("Invalid email or password.")

  end
end

