import selenium
from selenium import webdriver
from selenium.webdriver.common.keys import Keys

browser = webdriver.Chrome()
browser.get('http://stiki.ac.id')
searchLink = browser.find_element_by_class_name('fusion-main-menu-icon')
searchLink.click()

searchInput = browser.find_element_by_class_name('s')
searchInput.send_keys('kemahasiswaan' + Keys.RETURN)

judulLink = browser.find_element_by_css_selector('h2.entry-title>a')
judul = judulLink.text
print(judul)
browser.quit()
