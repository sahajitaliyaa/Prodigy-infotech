import requests
from bs4 import BeautifulSoup
import pandas as pd

def scrape_amazon_products(url, headers):
    # Send a GET request to the URL
    response = requests.get(url, headers=headers)
    
    # Parse the HTML content of the page with BeautifulSoup
    soup = BeautifulSoup(response.content, 'html.parser')
    
    # Initialize lists to store product information
    product_names = []
    product_prices = []
    product_ratings = []
    
    # Find product elements (this depends on the website structure)
    products = soup.find_all('div', {'data-component-type': 's-search-result'})
    
    for product in products:
        # Extract product name
        name = product.h2.text.strip()
        product_names.append(name)
        
        # Extract product price (handling cases where price might be missing)
        price = product.find('span', 'a-price-whole')
        if price:
            product_prices.append(price.text.strip())
        else:
            product_prices.append('N/A')
        
        # Extract product rating (handling cases where rating might be missing)
        rating = product.find('span', 'a-icon-alt')
        if rating:
            product_ratings.append(rating.text.strip())
        else:
            product_ratings.append('N/A')
    
    # Create a DataFrame to store the data
    data = {
        'Name': product_names,
        'Price': product_prices,
        'Rating': product_ratings
    }
    df = pd.DataFrame(data)
    
    return df

if __name__ == "__main__":
    # URL of the Amazon search results page (example)
    url = 'https://www.amazon.com/s?k=laptop'
    
    # Headers to mimic a browser visit
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3'}
    
    # Scrape the product data
    df = scrape_amazon_products(url, headers)
    
    # Save the data to a CSV file
    df.to_csv('amazon_products.csv', index=False)
    
    print("Scraping completed and data saved to 'amazon_products.csv'.")
