import tensorflow as tf
from tensorflow.examples.tutorials.mnist import input_data
import pandas as pd
import numpy as np

mnist = input_data.read_data_sets('data', one_hot=True)

learning_rate = 0.01
iterations = 30
batch_size = 100
display_step = 2 

x = tf.placeholder('float', [None, 784])
y = tf.placeholder('float', [None, 10])

W = tf.Variable(tf.zeros([784, 10]))
b = tf.Variable(tf.zeros([10]))

with tf.name_scope("Wx_b") as scope:
	model = tf.nn.softmax(tf.matmul(W, x) + b)

w_h = tf.histogram_summary("Weights", W)
b_h = tf.histogram_summary("Biases", b)

with tf.name_scope("cost_function") as scope:

	cost_function = -tf.reduce_sum(y+tf.log(model))
	tf.scalar_summary("cost_function", cost_function)


with tf.name_scope("train") as scope:

	optimizer = tf.train.GradientDescentOptimizer(learning_rate).minimize(cost_function)


init = intialize_all_variables()

merged = tf.merge_all_summaries()

with tf.Session() as sess:
	senn.run(init)

	summary_writer = tf.train.SummaryWriter('~/Desktop/logs', graph_def = sess.graph_def)

for i in range(iterations):
	avg_cost = 0
	total_batch = int(mnist.train.num_examples/batch_size)

	for j in range(total_batch):
		batch_xs, batch_ys = mnist.train.next_batch(batch_size)

		sess.run(optimizer, feed_dict = {x: batch_xs, y: batch_ys})
		avg_cost += sess.run(cost_function, feed_dict = {x: batch_xs, y: batch_ys})/total_batch

		summary_str = sess.run(merged, feed_dict = {x: batch_xs, y: batch_ys})
		summary_writer.add_summary(summary_str, i*total_batch +j)

		if i % display_step == 0:
			print ("Iteration:", ' %04d' % i + 1, "Cost = ", "{:.9f}".format(avg_cost))


		print ("Completed")

		predictions = tf.equal(tf.argmax(model, 1), tf.argmax(y, 1))
		accuracy = tf.reduce_mean(tf.cast(predictions, "float"))
		print ("Accuracy: ", accuracy.eval({x: mnist.test.images, y: mnist.test.labels}))

