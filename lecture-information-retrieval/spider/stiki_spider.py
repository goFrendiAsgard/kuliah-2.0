import scrapy, io

# scrapy runspider stiki_spider.py
class StikiSpider(scrapy.Spider):
    name = 'blogspider'
    start_urls = ['http://stiki.ac.id']

    def parse(self, response):
        for title in response.css('.entry-title'):
            judul = title.css('a ::text').extract_first()
            if judul:
                judul = judul.encode('utf-8')
                f = open('output.txt', 'a')
                f.write(judul + "\n")
                f.close()
            # yield {'title': judul}
            

        for next_page in response.css('a.pagination-next'):
            yield response.follow(next_page, self.parse)
